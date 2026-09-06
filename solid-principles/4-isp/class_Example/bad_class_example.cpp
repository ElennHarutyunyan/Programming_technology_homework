#include <iostream>

class IMultimediaProcessor {
public:
    virtual void playAudio() = 0;
    virtual void stopAudio() = 0;
    virtual void adjustVolume(int volume) = 0;
    
    virtual void playVideo() = 0;
    virtual void stopVideo() = 0;
    virtual void adjustBrightness(int brightness) = 0;
    
    virtual ~IMultimediaProcessor() = default;
};


class AudioPlayer : public IMultimediaProcessor {
public:
    void playAudio() override {
        std::cout << "Playing audio...\n";
    }
    
    void stopAudio() override {
        std::cout << "Stopping audio...\n";
    }
    
    void adjustVolume(int volume) override {
        std::cout << "Volume set to " << volume << "\n";
    }

    void playVideo() override {
        std::cout << "Error: AudioPlayer cannot play video!\n";
    }
    
    void stopVideo() override {
    }
    
    void adjustBrightness(int brightness) override {
    }
};

int main() {
    AudioPlayer player;
    player.playAudio();
    player.playVideo(); 
    return 0;
}