//
// Created by John Yeany on 6/28/18.
//
#include "include/model/todo.h"

todo::todo()
{
    //ctor
};

todo::todo(utility::string_t description, bool is_complete)
{
    m_description = description;
    m_is_complete = is_complete;
}

todo::~todo()
{
    //dtor
}

json::value todo::to_json()
{
    json::value todo_json = json::value::object();
    todo_json["id"] = json::value::string(to_string(m_id));
    todo_json["description"] = json::value::string(m_description);
    todo_json["is_complete"] = json::value::boolean(m_is_complete);
    return todo_json;
}

void todo::from_json(json::value todo_json)
{
    if (todo_json.has_field("id"))
    {
        utility::string_t str_id = todo_json["id"].as_string();
        boost::uuids::string_generator gen;
        m_id = gen(todo_json["id"].as_string());
    }
    else
    {
        boost::uuids::random_generator gen;
        m_id = gen();
    }
    m_description = todo_json["description"].as_string();
    m_is_complete = todo_json["is_complete"].as_bool();
}

boost::uuids::uuid todo::id()
{
    return m_id;
}

void todo::id(boost::uuids::uuid id)
{
    m_id = id;
}

utility::string_t todo::description()
{
    return m_description;
}

void todo::description(utility::string_t description)
{
    m_description = description;
}

bool todo::is_complete()
{
    return m_is_complete;
}

void todo::is_complete(bool is_complete)
{
    m_is_complete = is_complete;
}