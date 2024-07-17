#include <iostream>
#include <cassert>

using namespace std;
template <class T,size_t mcount>
class mk_array {
 friend ostream& operator <<(ostream& output, mk_array ar)
 {
    for (auto i=0;i<ar.count;i++)
        output << ar[i];
    return output;  // для cout << a << b;
 }
public:
    mk_array() {
        if (mcount==0) throw "aaa";
        parr = new T[mcount];
         assert(parr!=nullptr);
         count = mcount;
    }

    T& operator [](int i) {
        if (i<0 || count <=static_cast<size_t>(i) ) throw "aa";
        return parr[i];
    }

    ~mk_array() { delete [] parr;}
private:
    T* parr;
    size_t count;
};

int main()
{
    cout << "Hello World!" << endl;
    mk_array<int,6> ar;
    ar[0]=1;
    std::cout << ar[0] << endl;
  //  cout << ar;  сгенерирует operator<<(cout,arr);

    return 0;
}
