#include <iostream>
#include <math.h>
using namespace std;

class CFraction{
    private: 
        int num;
        int den;
    public:
        void ImportData(CFraction &CFraction_);
        void ExportData(CFraction &CFraction_);
        void Compact(CFraction &CFraction_);
        friend CFraction operator+ (const CFraction& CFraction_1, const CFraction& CFraction_2);
        friend CFraction operator- (const CFraction& CFraction_1, const CFraction& CFraction_2);
        friend CFraction operator* (const CFraction& CFraction_1, const CFraction& CFraction_2);
        friend CFraction operator/ (const CFraction& CFraction_1, const CFraction& CFraction_2);
};

