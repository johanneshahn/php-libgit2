//
//  status.cpp
//  php-libgit2
//
//  Created by Johannes Hahn on 05.06.15.
//  Copyright (c) 2015 Johannes Hahn. All rights reserved.
//

#include "status.h"

using namespace PhpLibgit2;


Status::~Status() {}

/**
 *  Gather file status information and populate the git_status_list
 *  @return int
 */
Php::Value Status::php_git_status_list_new()
{
    int status = 0;
    if(_git_repository != NULL){
       status = check_lg2(git_status_list_new(&_gsl, _git_repository, &_gso.statusopt));
    }else{
        Php::error << NO_GIT_REPOSITORY << std::flush;
    }
    return status;
}

/**
 *  Gets the count of status entries in this list.
 *  @return int
 */
Php::Value Status::php_git_status_list_entrycount()
{
    
    
    if(_gsl == NULL){
        php_git_status_list_new();
    }
    
    return static_cast<int>( git_status_list_entrycount(_gsl) );
}





