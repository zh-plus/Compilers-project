int global;
struct my_struct
{
    int code;
    char data;
};
int test_1_r02()
{
    struct my_struct obj;
    obj.code = global;
    global = global + 1;
}
