#ifndef BOMBFIRE_H
#define BOMBFIRE_H

#include <CommonClass.h>
enum Position{
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
};

class CBombFire : public CSprite
{
    public:
        //CBombFire( const char *szCloneName, const char *szMyName, const float fTime, int lastnum,Position sid);
        CBombFire(const char *szCloneName,const char *szName,int lastnum,Position sid);
        virtual ~CBombFire();
        void Init();
    protected:
    private:
        Position side;
        int lastNum;
};

#endif // BOMBFIRE_H
