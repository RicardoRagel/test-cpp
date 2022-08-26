void non_static_print();
//static void static_print(); // IT IS NOT NECESSARY HERE, actually,
                              // it is better it is only in the source file
                              // where the class can call it, and the source
                              // file not, because a static function is local,
                              // so another file (main.cpp for example), should
                              // not be able to call it.

class Class
{
    public:
        Class();

        static int getStaticVariable();
        static int variable;
        
        void callStaticPrint();
};