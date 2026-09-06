#include <iostream>
#include <string>

class EmailNotifier {
public:
    void sendEmail(std::string const& msg) {
        std::cout << "Sending Email: " << msg << "\n";
    }
};

class SMSNotifier {
public:
    void sendSMS(std::string const& msg) {
        std::cout << "Sending SMS: " << msg << "\n";
    }
};

class NotificationManager {
private:
    EmailNotifier emailNotifier; 
    SMSNotifier   smsNotifier;   

public:
    void sendNotification(std::string const& msg, bool useEmail) {
        if (useEmail) {
            emailNotifier.sendEmail(msg);
        } else {
            smsNotifier.sendSMS(msg); 
        }
    }
};

int main() {
    NotificationManager manager;
    manager.sendNotification("Hello via Email!", true);
    manager.sendNotification("Hello via SMS!", false);
    return 0;
}