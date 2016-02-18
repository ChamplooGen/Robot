#include "network.h"
#include <iostream>

Network * Network::instance = 0;

        Network::Network()
        {        }
        Network::~Network(){}

        void Network::Listen() {
            std::cout <<" I am ready for your orders, Master"<<std::endl;
        }
        void Network::Connect() {
            std::cout <<" I'm here and ready for work!"<<std::endl;
        }
        void Network::Disconnect() {
            std::cout <<" I'm out. Farewell."<<std::endl;
        }
        void Network::Send() {
            std::cout <<" All enemies will be brought to hell, Master!"<<std::endl;
        }
        void Network::Get(){
            std::cout <<" What do you want for me to get?"<<std::endl;
        }
        ////====================================================


        Network * Network::GetInstance()
        {
            if (instance == 0) instance = new Network();
            return instance;
        }

        void Network::DestroyInstance()
        {
            if (instance != 0) delete instance;
        }
