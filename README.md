# Restweb
Sample code of cpprestsdk (casablanca)


This repo contains a sample of cpprestsdk server side in very simple format.
sample handles 4 method of http request [put, get,post and delete].
Allows adding, updating, listing, and removing to do items.

project structure 

[main.cpp]
[include/handler.h]
[include/router.h]
[include/model/todo.h]
[include/service/todo_service.h]
[src/model/todo.cpp]
[src/service/todo_service.cpp]
[src/handler.cpp]


How to compile :

cmake .

make

run server 
./Build/bin/restserver

Current setup is to build on mac. DBMS sub-project is not setup


{#dbms folder is a independent project right now to access database before enable to install some prerequsites}
1)
 install postgresql;
 install pqxx  (sudo apt-get install libpqxx-dev)
 and libpq  if it is not installed with postgresql  ((sudo apt-get install libpq-dev)
 
dbms support can be added ( right now  Postgresql only) by doing following steps 
1) uncomment  line 5 of handler.h 

>//#include "../dbms/include/Dbms.h"

2) for testing uncomment line 43 and 44 of handler.cpp
>	//Dbms* d  = new Dbms();
>   //d->connect();
 
How to complie :

cmake . -DDBMS=ON
make

run server 
./Build/bin/restserver
 
now all done . just implement/replace own logic.
