#pragma once

/*
    Type Definitions:
        RESULT,
        &RESULT::new<tagRESULT>,
        ...
    Structs:
        tagRESULT,
        ...
    Defines:
        None
*/

typedef struct
{
    long l;
    void* res0;
    void* data[8];
    long* plong;
    

    
} tagRESULT;

typedef tagRESULT* RESULT, PRESULT;