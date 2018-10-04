# C++ REST Todo

This repo contains a sample of cpprestsdk server side for creating a todo list.
Sample handles 4 method of http request [put, get,post and delete].
Allows adding, updating, listing, and removing todo items.

Endpoints:
GET     /todo  
POST    /todo  
PUT     /todo  
DELETE  /todo/{id}  


project structure 

[main.cpp]  
[include/handler.h]  
[include/router.h]  
[include/model/todo.h]  
[include/service/todo_service.h]  
[src/model/todo.cpp]  
[src/service/todo_service.cpp]  
[src/handler.cpp]  


Current setup is to build on mac. How to compile :

cmake .

make

run server 
./Build/bin/restserver


 

 

