void non_static_print();
static void static_print();

class Class
{
    public:
        Class();

        static int getStaticVariable();
        static int variable;
        
        void callStaticPrint();
};