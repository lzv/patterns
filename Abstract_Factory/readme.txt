Абстрактная фабрика применяется, когда в приложении должна использоваться группа объектов одного типа, и таких типов (наборов объектов) несколько. Выбор типа производится созданием объекта нужного класса фабрики, а уже этот объект через свои переопределяемые методы создает объекты нужного типа. Для изменения набора объектов достаточно поменять объект фабрики. 

Но есть и недостатки - при добавлении нового типа объектов, или нового объекта для всех типов, приходится модицифировать и классы фабрик.

Пример: объекты - элементы управления в приложении - кнопка, меню, строка ввода, и т.п. Эти объекты выглядят по разному в разных ОС, что определяет их тип. Используя фабрику, можно получать эти объекты, не заботясь о их типе, который выбирается только один раз - при выборе фабрики.

Пример в исходном коде: объекты - символы, а их тип - это их размер - большие или маленькие. В дальнейшем можно добавить как новый символ, так и новый тип, не меняя уже работающий код.
