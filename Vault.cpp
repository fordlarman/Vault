/*
* Vault - Encrypted Password Manager 
*/


#include <iostream>
#include <string>
#include <cstring>
#include <system_error>
//Universal Datatypes

//need to take input from user
std::string file = "file.txt";
std::string password = "pa33word";

//Encrypt file
void encrypt(std::string file, std::string password){
  std::string com1 = "openssl enc -aes-256-cbc -salt -in ";
  std::string com2 = " -out file.enc -k ";
  char * cmd;
  std::string fincom = com1 + file + com2 + password;
  std::cout << "command: " << fincom << "" << std::endl; //needs a space after fincom for command to work!
  strcpy(cmd, fincom.c_str());
  try
    {
        system(cmd); // attempt to detach a non-thread
    }
    catch(const std::system_error& e)
    {
        std::cout << "Caught system_error with code "
                     "[" << e.code() << "] meaning "
                     "[" << e.what() << "]\n";
    }
}


//Decrypt file
void decrypt(std::string file){


  //read(file);
}


//Read data
void read(std::string file) {
  

}


//Banner
void banner(){
  std::cout << "V A U L T " << std::endl;
  std::cout << "Encrypted Password Manager" << std::endl;

}

//Search for entry
//int search(){

  //return id;
//}

//vault instance menu
void subMenu(){
  int quit = 0;
  std::string select;
  while(quit == 0){
    //std::cout << "[1] - Import CSV File" << std::endl; //input file path and Vault will encrypt and store the data locally for access.
    std::cout << "[1] - Search Passwords" << std::endl; //Search your encrypted File for specific Password details.
    std::cout << "[2] - Add Credentials" << std::endl; //Add new entry to file
    std::cout << "[3] - Remove Credentials" << std::endl;// Remove existing entry from file.
    std::cout << "[4] - Export Password File" << std::endl;
    std::cin >> select;
    //check for "quit" command
    if(select == "quit"){
      std::exit(1);
    }else{
      encrypt(file, password);

    }
  }
}


//Main menu
void mainMenu(){
  int quit = 0;
  std::string select;
  while(quit == 0){
    std::cout << "[1] Access Vault" << std::endl;
    std::cout << "[2] Create Vault" << std::endl;
    std::cout << "[3] Delete Vault" << std::endl;
    if (select == "quit"){
      std::exit(1);
    }else{
      subMenu();
    }

  }
}


//Main
int main(){
  banner();
  mainMenu();
};


