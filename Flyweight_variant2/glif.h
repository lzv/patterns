#ifndef GLIF_H
#define GLIF_H

#include <vector>
using std::vector;

class glif 
{
    friend class composite;
    friend class root;
    friend class glifFactory;
    
	protected:
        glif () {}
        virtual ~glif () {}
        
        glif (const glif &);
        glif & operator = (const glif &);

        virtual void delete_self () {}
        
	public:
        virtual void Add (glif *) {}
        virtual void Delete (unsigned int) {}   // В параметре нельзя использовать glif *, так как не проверяем равенство.
        virtual unsigned int Count () {return 0;}
        virtual glif * GetChild (unsigned int) {return nullptr;}
        
        virtual char get_type () = 0;
};

class symbol : public glif 
{
    friend class glifFactory;
    
    private:
        char c;
        
    protected:
        symbol (char c) : c(c) {}
        ~symbol () {}
        
        symbol (const symbol &);
        symbol & operator = (const symbol &);
        
    public:
        char get_type () {return 's';}
};

class composite : public glif 
{
    friend class glifFactory;
    
    protected:
        vector <glif *> children;
        
        composite () {}
        virtual ~composite () {}
        
        composite (const composite &);
        composite & operator = (const composite &);
        
        virtual void delete_self ()
        {
            for (glif * i: children) i->delete_self();
            delete this;
        }
        
	public:
        virtual void Add (glif * obj)
        {
            // Объекты symbol нельзя проверять на равенство, так как они приспособленцы.
            // Объект root нельзя добавлять в иерархию, так как он может быть только корнем.
            if (obj->get_type() != 'r')
            {
                bool exist = false;
                if (obj->get_type() == 'c')
                    for (auto i: children)
                        if (i == obj) {
                            exist = true;
                            break;
                        }
                if (!exist) children.push_back(obj);
            }
        }

		virtual void Delete (unsigned int index)
        {
            if (index < children.size())
            {
                children[index]->delete_self();
                children.erase(children.begin() + index);
            }
        }

        // Получаем количество всех дочерних объектов объектов, а не только листьев.
		virtual unsigned int Count ()
        {
            unsigned int result = 0;
            for (auto i: children) result += i->Count();
            result += children.size();
            return result;
        }

		virtual glif * GetChild (unsigned int index)
        {
            return index < children.size() ? children[index] : nullptr;
        }
        
        virtual char get_type ()
        {
            return 'c';
        }
};

class root : public composite
{
    public:
        root () {}
        
        ~root ()
        {
            for (glif * i: children) i->delete_self();
        }
};

#endif // GLIF_H
