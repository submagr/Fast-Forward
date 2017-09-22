#include<iostream>
using namespace std;

class IVideo{
public:
    virtual void createVideo() = 0;
    virtual void attachVideo() = 0;
};

class IAudio{
public:
    virtual void createAudio() = 0;
    virtual void attachAudio() = 0;
};

class IMag{
public:
    virtual void createMag() = 0;
    virtual void attachMag() = 0;
};

class ExpVideo: public IVideo{
public:
    virtual void createVideo(){
        cout << "ExpVideo Video created" << endl;
    }
    virtual void attachVideo(){
        cout << "ExpVideo Video attached" << endl;
    }
};

class ExpAudio: public IAudio{
public:
    virtual void createAudio(){
        cout << "ExpAudio Audio created" << endl;
    }
    virtual void attachAudio(){
        cout << "ExpAudio Audio attached" << endl;
    }
};

class ExpMag: public IMag{
public:
    virtual void createMag(){
        cout << "ExpMag Mag created" << endl;
    }
    virtual void attachMag(){
        cout << "ExpMag Mag attached" << endl;
    }
};

class FireMag: public IMag{
public:
    virtual void createMag(){
        cout << "FireMag Mag created" << endl;
    }
    virtual void attachMag(){
        cout << "FireMag Mag attached" << endl;
    }
};

class FireVideo: public IVideo{
public:
    virtual void createVideo(){
        cout << "FireVideo Video created" << endl;
    }
    virtual void attachVideo(){
        cout << "FireVideo Video attached" << endl;
    }
};

class FireAudio: public IAudio{
public:
    virtual void createAudio(){
        cout << "FireAudio Audio created" << endl;
    }
    virtual void attachAudio(){
        cout << "FireAudio Audio attached" << endl;
    }
};


class IFactory{
public:
    virtual IVideo* BuildVideo() = 0;  
    virtual IAudio* BuildAudio() = 0;  
    virtual IMag* BuildMag() = 0;  
};

class ExpFactory:public IFactory{
public:
    IVideo* BuildVideo(){
        return new ExpVideo();
    }
    IAudio* BuildAudio(){
        return new ExpAudio();
    }
    IMag* BuildMag(){
        return new ExpMag();
    }
};

class FireFactory:public IFactory{
public:
    IVideo* BuildVideo(){
        return new FireVideo();
    }
    IAudio* BuildAudio(){
        return new FireAudio();
    }
    IMag* BuildMag(){
        return new FireMag();
    }
};

int main(){
    IFactory *factory = NULL;

    factory = new FireFactory();
    IVideo* vid = factory->BuildVideo();
    vid->createVideo();
    vid->attachVideo();

    IAudio* aud = factory->BuildAudio();
    aud->createAudio();
    aud->createAudio();
    return 0;
}
