typedef struct{
    int read;//read pointer,customer read data drom buffer
    int write;//write pointer,producer write data in  buffer
    char buf[10];//10 buffer

}shared_struct;

