#ifndef BOMB_H
#define BOMB_H

#include <CommonClass.h>
#include "Player.h"

class CBomb : public CSprite
{
    public:
        CBomb(const char *szName,int pow,CPlayer *owner);
        virtual ~CBomb();
        void Init();
        const char *GetOwnerName()        {return ownName;}
    protected:
    private:
        int power;
        CPlayer *own;
        const char *ownName;
};

#endif // BOMB_H
