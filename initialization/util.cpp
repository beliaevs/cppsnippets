#include "util.h"

void extfoo(NoCopyMove n)
{

}

NoCopyMove extbar()
{
    return NoCopyMove();
}
/*
NoCopyMove extbaz()
{
    NoCopyMove res;
    return res; // error: use of deleted function ‘NoCopyMove::NoCopyMove(const NoCopyMove&)
}
*/