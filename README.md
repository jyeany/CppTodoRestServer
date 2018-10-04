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

Current setup is to build on mac.
 
How to compile :

cmake .
make

run server 
./Build/bin/restserver
 

