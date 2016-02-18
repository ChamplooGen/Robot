#ifndef NETWORK_H
#define NETWORK_H

class Network
{
    private:
        static Network * instance;
        Network();
    public:
        ~Network();
        static Network * GetInstance();
        static void DestroyInstance();

        virtual void Listen();	// слушать эфир
        virtual void Connect();
        virtual void Disconnect();
        virtual void Send();	// отправить данные
        virtual void Get();		// принять данные
};

#endif // NETWORK_H
