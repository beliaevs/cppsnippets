#pragma once

class NoCopyMove
{
    public:
    NoCopyMove() = default;
    NoCopyMove(const NoCopyMove&) = delete;
    NoCopyMove(NoCopyMove&&) = delete;
};

void extfoo(NoCopyMove n);
NoCopyMove extbar();
NoCopyMove extbaz();
