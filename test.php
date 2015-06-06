<?php


    
    $phplibgit2_repository = new PhpLibgit2\Repository();
    $phplibgit2_status = new PhpLibgit2\Status();
    
    //do: git init my_test
    if($phplibgit2_repository->git_repository_open('/tmp/my_test')){
        
        echo('git status entries(untracked, modified etc.): '. $phplibgit2_status->git_status_list_entrycount(). "\n");
    }else{
        
        //do: git init my_test
        echo('git init: '. $phplibgit2_repository->git_repository_init('/tmp/my_test', FALSE). "\n");
        
        //do: git init --bare my_test
        //$phplibgit2_repository->git_repository_open('/tmp/my_test.git');
    }
    
    
    
