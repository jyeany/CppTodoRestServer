#include "../include/router.h"

router::router()
{
    //ctor
}

router::~router()
{
    //dtor
}

void router::route_get(http_request message)
{
    utility::string_t path = message.absolute_uri().to_string();
    vector<utility::string_t> path_parts = message.absolute_uri().split_path(path);
    vector<string>::iterator it;
    int path_index = 0;
    bool is_todo = false;
    for (it = path_parts.begin(); it != path_parts.end(); it++, path_index++)
    {
        if (path_index == 0 && *it == "todo" && path_parts.size() == 1)
        {
            vector<todo> todos = m_todo_service.find_all();
            vector<todo>::iterator it;
            utility::string_t result;
            json::value val = json::value::object();
            val["todos"] = json::value::array();
            int index = 0;
            for (it = todos.begin(); it != todos.end(); it++, index++)
            {
                val["todos"][index] = it->to_json();
            }
            message.reply(status_codes::OK, val.serialize(), "application/json");
        }

        if (path_index == 0 && *it == "todo" && path_parts.size() == 2)
        {
            is_todo = true;
        }

        if (path_index == 1 && is_todo)
        {
            boost::uuids::string_generator gen;
            boost::uuids::uuid id = gen(*it);
            todo result = m_todo_service.find(id);
            json::value result_json = result.to_json();
            message.reply(status_codes::OK, result_json.as_string(), "application/json");
        }
        ucout << *it << endl;
    }
}

void router::route_post(http_request message)
{
    utility::string_t json_body = message.extract_string().get();
    json::value json_todo = json::value::parse(json_body);
    todo todo;
    todo.from_json(json_todo);
    if (json_todo.has_field("id"))
    {
        m_todo_service.update_todo(todo);
    }
    else
    {
        m_todo_service.add_todo(todo);
    }
    message.reply(status_codes::Created);
}

void router::route_delete(http_request message)
{
    utility::string_t path = message.absolute_uri().to_string();
    vector<utility::string_t> path_parts = message.absolute_uri().split_path(path);
    if (path_parts.size() == 2 && path_parts.at(0) == "todo")
    {
        boost::uuids::string_generator gen;
        utility::string_t str_id = path_parts.at(1);
        boost::uuids::uuid id = gen(str_id);
        m_todo_service.delete_todo(id);
        message.reply(status_codes::NoContent);
    }
    else
    {
        message.reply(status_codes::NotFound);
    }
}