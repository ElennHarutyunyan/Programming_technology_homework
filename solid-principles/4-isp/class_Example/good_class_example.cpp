#include <iostream>


class IAudioProcessor {
public:
    virtual void playAudio() = 0;
    virtual void stopAudio() = 0;
    virtual void adjustVolume(int volume) = 0;
    virtual ~IAudioProcessor() = default;
};

class IVideoProcessor {
public:
    virtual void playVideo() = 0;
    virtual void stopVideo() = 0;
    virtual void adjustBrightness(int brightness) = 0;
    virtual ~IVideoProcessor() = default;
};

class AudioPlayer : public IAudioProcessor {
public:
    void playAudio() override {
        std::cout << "Playing audio cleanly...\n";
    }
    
    void stopAudio() override {
        std::cout << "Stopping audio...\n";
    }
    
    void adjustVolume(int volume) override {
        std::cout << "Volume set to " << volume << "\n";
    }
};

class VideoPlayer : public IVideoProcessor {
public:
    void playVideo() override {
        std::cout << "Playing video smoothly...\n";
    }
    
    void stopVideo() override {
        std::cout << "Stopping video...\n";
    }
    
    void adjustBrightness(int brightness) override {
        std::cout << "Brightness set to " << brightness << "\n";
    }
};

int main() {
    AudioPlayer audioDevice;
    audioDevice.playAudio();
    audioDevice.adjustVolume(50);

    VideoPlayer videoDevice;
    videoDevice.playVideo();

    std::cout << "Good design compiled successfully without forced stub methods.\n";
    return 0;
}