# C++ REST Todo

This repo contains a sample of cpprestsdk server side for creating a todo list.
Sample handles 4 method of http request [put, get,post and delete].
Allows adding, updating, listing, and removing todo items.

### Endpoints:  
GET     /todo  
POST    /todo  
PUT     /todo  
DELETE  /todo/{id}  


### project structure: 

[main.cpp]  
[include/handler.h]  
[include/router.h]  
[include/model/todo.h]  
[include/service/todo_service.h]  
[src/model/todo.cpp]  
[src/service/todo_service.cpp]  
[src/handler.cpp]  


### Build
There are currently two hardcoded include directories specific to mac in CMakeLists.txt.
Please update them as appropriate for your system:  
```
include_directories("/usr/local/Cellar/libpqxx/6.2.4/include")
and 
set(OPENSSL_ROOT_DIR /usr/local/Cellar/openssl/1.0.2o_2)
```

How to compile :

```
# build project
cmake .
make

# run server 
./Build/bin/restserver
```


 

 

