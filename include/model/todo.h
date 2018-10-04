//
// Created by John Yeany on 6/28/18.
//
#ifndef TODO_H
#define TODO_H
#include <cpprest/json.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/string_generator.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "../stdafx.h"

using namespace web;
using boost::lexical_cast;

class todo {

    public:
        todo();
        todo(utility::string_t description, bool is_complete);
        virtual ~todo();
        json::value to_json();
        void from_json(json::value todo_json);
        boost::uuids::uuid id();
        void id(boost::uuids::uuid id);
        utility::string_t description();
        void description(utility::string_t description);
        bool is_complete();
        void is_complete(bool is_complete);

    private:
        boost::uuids::uuid m_id;
        utility::string_t m_description;
        bool m_is_complete;
};


#endif //TODO_H
