#include <iostream>
#include <string>
#include <memory>

class Notifier {
public:
    virtual ~Notifier() = default;
    virtual void notify(std::string const& msg) = 0;
};

class EmailNotifier : public Notifier {
public:
    void notify(std::string const& msg) override {
        std::cout << "Sending Email via Abstraction: " << msg << "\n";
    }
};

class SMSNotifier : public Notifier {
public:
    void notify(std::string const& msg) override {
        std::cout << "Sending SMS via Abstraction: " << msg << "\n";
    }
};

class NotificationManager {
private:
    Notifier& notifier; 

public:
    explicit NotificationManager(Notifier& n) : notifier(n) {}

    void sendNotification(std::string const& msg) {
        notifier.notify(msg);
    }
};

int main() {
    EmailNotifier emailObj;
    SMSNotifier smsObj;

    NotificationManager emailManager(emailObj);
    emailManager.sendNotification("Hello through good DIP design (Email)!");

    NotificationManager smsManager(smsObj);
    smsManager.sendNotification("Hello through good DIP design (SMS)!");

    std::cout << "Good DIP design compiled and ran successfully.\n";
    return 0;
}