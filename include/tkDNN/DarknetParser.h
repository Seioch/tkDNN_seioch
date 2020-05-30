#pragma once
#include <iostream>
#include "tkdnn.h"

namespace tk { namespace dnn {

    struct darknetFields_t{
        int width = 0;
        int height = 0;

    };

    std::string darknetParseType(const std::string& line){
            size_t start = line.find("[");
            size_t end  = line.find("]");
            if( start == std::string::npos || end == std::string::npos)
                return "";
            start++;
            std::string type = line.substr(start, end-start);
            return type;
    }

    darknetFields_t parseFields(const std::string& line){
        
    }



    tk::dnn::Network* DarknetParser(std::string cfg_file) {

        tk::dnn::dataDim_t dim;
        tk::dnn::Network *net = new tk::dnn::Network(dim);

        std::ifstream if_cfg(cfg_file);
        if(!if_cfg.is_open())
            FatalError("cloud not open cfg file: " + cfg_file);

        std::string line;
        while(std::getline(if_cfg, line)) {
            // remove comments
            std::size_t found = line.find("#");
            if ( found != std::string::npos ) {
                line = line.substr(0, found);
            }

            // skip empty lines
            if(line.size() == 0)
                continue;
            
            std::string type = darknetParseType(line);
            if(type.size() > 0) {
                std::cout<<"type: "<<type<<"\n";
            }
        }
    }
        
    

}}