#include <iostream>
#include <memory>

int main(int argc, char* argv[])
{
    std::shared_ptr<int> p_x(new int);

    std::cout<<"p_x use count: "<<p_x.use_count()<<"\n";
    *p_x = 5; // ’de-reference’ to alter contents
    
    // Use this pointer elsewhere
    std::shared_ptr<int> p_y = p_x;
    std::cout<<"p_x use count: "<<p_x.use_count()<<"\n";
    
    p_y.reset();
    std::cout<<"p_x use count: "<<p_x.use_count()<<"\n";
    
    std::weak_ptr<int> p_w = p_x;
    std::cout<< "p_w expired: " << p_w.expired() <<"\n";

    p_x.reset();
    std::cout<<"p_x use count: "<<p_x.use_count()<<"\n";
    // The weak_ptr expires qhen the variable is reseted.
    std::cout<< "p_w expired: " << p_w.expired() <<"\n";
    
    return 0;
}