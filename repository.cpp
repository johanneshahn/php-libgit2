//
//  repository.cpp
//  php-libgit2
//
//  Created by Johannes Hahn on 06.06.15.
//  Copyright (c) 2015 Johannes Hahn. All rights reserved.
//

#include "repository.h"



/**
 *  PHP includes
 */

using namespace PhpLibgit2;



/**
 *  C++ constructor and destructor
 */
Repository::Repository() {git_libgit2_init();}
Repository::~Repository() {git_libgit2_shutdown();}

/**
 *  Get param _is_bare
 *  @return Php::Value is_bare
 */
Php::Value Repository::getIsBare() const
{
    return _is_bare;
}


/**
 *  Get param _path
 *  @return Php::Value path
 */
Php::Value Repository::getPath() const
{
    return _path;
}


/**
 *  Creates a new Git repository in the given folder.
 *  @param  params
 *  @return mixed error git_repository
 */
Php::Value Repository::php_git_repository_init(Php::Parameters &params)
{
    int status = 0;
    _path = params[0];
    _is_bare = params[1];
    
    
    status = check_lg2(git_repository_init(&_git_repository, _path, _is_bare));
    return status;
}

/**
 *  Open a git repository.
 *  @param  params
 *  @return mixed error git_repository
 */
Php::Value Repository::php_git_repository_open(Php::Parameters &params)
{
    int status = 0;
    if(!params.empty()){
        _path = params[0];
    }
    status = check_lg2(git_repository_open(&_git_repository, _path));
    return status;
}

/**
 *  Open a bare repository on the serverside.
 *  @param  params
 *  @return mixed error git_repository
 */
Php::Value Repository::php_git_repository_open_bare(Php::Parameters &params)
{
    int status = 0;
    if(!params.empty()){
        _path = params[0];
    }
    
    status = check_lg2(git_repository_open_bare(&_git_repository, _path));
    return status;
    
}

/**
 *  Check if a repository is bare
 *  @param  params
 *  @return int
 */
Php::Value Repository::php_git_repository_is_bare()
{
    int status = 0;
    if(_git_repository != NULL){
        status = git_repository_is_bare(_git_repository);
    }else{
        Php::error << NO_GIT_REPOSITORY << std::flush;
    }
    return status;
}


