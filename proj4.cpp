/*
Name: proj4.cpp
Purpose: This program is an interactive menu which assists the user in renting a car. The menu has multiple options such as read a list of cars from an agencyfrom a file, output the list of cars and agencies to the screen, estimate the price to rent a car from a specific agency, output a list of available cars from each agency to the screen, find the most expensive car,  display all sensors currently outfitted on the agency fleet, find the most expensive available car, and exit the program.
Author: Ethan M. Park
*/
#include <iostream>
#include <fstream>
#include "proj4.h"

using namespace std;

/*This function takes a pointer to the agency class and returns nothing.*/
/*It takes a given user input file and reads the information into the agency class using the ReadAllData method.*/
void read_data (class RentalAgency *RentalPlace);
/*This function takes a pointer to the agency class and returns nothing.*/
/*It takes the agency information from the agency class and outputs it to the screen as well as reads it to a file using the PrintCarsData method in the header to output car info.*/
void print_all_info(class RentalAgency *RentalPlace);
/*This function takes a pointer to the agency class holding agency information and returns nothing.*/
/*It asks the user what car they would like to rent, and the number of days they would like to rent it and estimates the cost using EstimateCost method.*/
void estimate_car_price(class RentalAgency *RentalPlace);
/*This function takes a pointer to the agency class holding agency information and returns nothing.*/
/*It finds the most expensive car using information from the agencyclass and the get methods of the header and outputs its information to the screen.*/
void most_expensive(class RentalAgency *RentalPlace);
/*This function takes a pointer to an array of structs holding agency information and returns nothing.*/
/*It outputs the information of only available cars to the screen using the information from the agencyclass and the PrintAvailableCars method.*/
void check_availability(class RentalAgency *RentalPlace);
/*This function takes a pointer to the agency class holding agency information and returns nothing.*/
/*It outputs how many of each sensor is currently equipt on the agencies fleet.*/
void print_all_sensors(class RentalAgency *RentalPlace);
/*This function takes a pointer to the agency class holding agency information and returns nothing.*/
/*It finds the most expensive available car and asks the user if they would like to purchase the car.*/
void most_expensive_available(class RentalAgency *RentalPlace);

/*Initialze static members to 0*/
int CarSensor::gps_cnt=0;
int CarSensor::camera_cnt=0;
int CarSensor::lidar_cnt=0;
int CarSensor::radar_cnt=0;

int main(){
	RentalAgency RentalPlace[1];
	RentalAgency *RentalPlace_Pt = RentalPlace;
	int userInput;
	for(;;){
		cout << "Enter 1 to read agency and car data." << endl;
		cout << "Enter 2 to display all cars." << endl;
		cout << "Enter 3 to estimate rental cost on a selected car." << endl;
		cout << "Enter 4 to find the most expensive car." << endl;
		cout << "Enter 5 to display only available cars." << endl;
		cout << "Enter 6 to display all sensors currently outfitted on the agency fleet." << endl;
		cout << "Enter 7 to find the most expensive available car." << endl;
		cout << "Enter 8 to exit." << endl;
		cout << endl;
		cout << "Your entry: ";
		cin >> userInput;
			switch (userInput){
				case 1: read_data(RentalPlace_Pt);
					break;
				case 2: print_all_info(RentalPlace_Pt);
					break;
				case 3: estimate_car_price(RentalPlace_Pt);
					break;
				case 4: most_expensive(RentalPlace_Pt);
					break;
				case 5: check_availability(RentalPlace_Pt);
					break;
				case 6: print_all_sensors(RentalPlace_Pt);
					break;
				case 7: most_expensive_available(RentalPlace_Pt);
					break;
				case 8: return 0;
				default: cout << "Error: Enter a valid number." << endl;
					break;
			}
		cout << endl;
		RentalPlace_Pt = RentalPlace;
	}
	return 0;
}
/*The function is given an agency class and fills it with and user specified file.*/
/*Here I asked the user for a file that they want read and used the ReadAllData method to stort the information in the agency class.*/
void read_data (class RentalAgency *RentalPlace){
	ifstream inputStream;
	char filename[50];
	cout << "Enter the file name: ";
	cin >> filename;
	inputStream.open(filename);
	RentalPlace->ReadAllData(inputStream);
	inputStream.close();
}
/*This function takes car information from an array of stucts and prints it to the screen.*/
/*If the array is empty the function will output an error message and go back to the menu.*/
/*For this function I simply called the PrintAllData method to output all the agencies information to the screen and to a user designated file.*/
void print_all_info(class RentalAgency *RentalPlace){
	int i, j, k;
	ofstream outputStream;
	char filename[50];
	/*Check to see if data has been entered from and input file, an error message will display if not.*/
	if (RentalPlace->inventory[0].GetYear() == 0){
		cout << "Error: No data detected" << endl;
	}
	else{
		cout << "Enter the file name: ";
		cin >> filename;
		outputStream.open(filename);
		RentalPlace->PrintAllData(outputStream);
		outputStream.close();
	}
}
/*This function takes car information from the agencyclass and estimates the cost to rent a user specified car from a user specifed agency for a user specifed amount of days*/
/*If the array is empty the function will output an error message and go back to the menu.*/
/*After the user specified info has been set the info is given to the rentalagency class, the EstimateCost method will output the estimated cost.*/
void estimate_car_price(class RentalAgency *RentalPlace){
	int carNumber, i, j, k = 0;
	ofstream outputStream;
	char filename[50];
	char agency_name[10];
	char *agency_name_pt = agency_name; //
	float multiplier, totalPrice;
	/*Check to see if data has been entered from and input file, an error message will display if not.*/
	if (RentalPlace->inventory[0].GetYear() == 0){
		cout << "Error: No data detected" << endl;
	}
	else{
		cout << "Enter the file name: ";
		cin >> filename;
		outputStream.open(filename);
		RentalCar *Car_Ptr = RentalPlace->inventory;
		cout << "Enter the car you would like to rent. Please enter 1-5: ";
		cin >> carNumber;
		for(i=1;i<carNumber;i++){
			Car_Ptr++;
		}
		cout << "How many days would you like to rent this car: ";
		cin >> multiplier;
		cout << "The estimated cost for selected car is: ";
		outputStream << "The estimated cost for selected car is: ";
		cout << "$" << Car_Ptr->EstimateCost(multiplier)<< endl;
		outputStream << "$" << Car_Ptr->EstimateCost(multiplier) << endl;
	}
}
/*This function takes car information from the agencyclass and finds the highest priced car, displaying its information to the screen.*/
/*If the array is empty the function will output an error message and go back to the menu.*/
/*I use a for loop and an if statement to systematically compare the price member of each choosing the greatest member as the value that will be displayed.*/
void most_expensive(class RentalAgency *RentalPlace){
	int i, j, most_expensive = 0;
	ofstream outputStream;
	char filename[50];
	/*Check to see if data has been entered from and input file, an error message will display if not.*/
	if (RentalPlace->inventory[0].GetYear() == 0){
		cout << "Error: No data detected" << endl;
	}
	else{
		cout << "Enter the file name: ";
		cin >> filename;
		outputStream.open(filename);
		cout << "The most expensive car is:" << endl;
		outputStream << "The most expensive car is:" << endl;
		RentalCar *Car_Ptr = RentalPlace->inventory;
		RentalCar *Expensive_Ptr = RentalPlace->inventory;
		Car_Ptr++;
		for(j=1;j<5;j++,Car_Ptr++){
			if (Car_Ptr->GetBasePrice() > Expensive_Ptr->GetBasePrice()){
				Expensive_Ptr = Car_Ptr;
			}
		}
		Expensive_Ptr->Print(outputStream);
	}
}
/*This function takes car information from an array of stucts and outputs all avaliable cars to the screen.*/
/*If the array is empty the function will output an error message and go back to the menu.*/
/*For loop that calls the PrintAvailableCars method to output available cars.*/
void check_availability(class RentalAgency *RentalPlace){
	ofstream outputStream;
	char filename[50];
	/*Check to see if data has been entered from and input file, an error message will display if not.*/
	if (RentalPlace->inventory[0].GetYear() == 0){
		cout << "Error: No data detected" << endl;
	}
	else{
		cout << "Enter the file name: ";
		cin >> filename;
		outputStream.open(filename);
		RentalPlace->PrintAvailableCars(outputStream);
	}
}
/*This function takes car information from an array of stucts and outputs how many of each sensor the fleet is currently equipt with.*/
/*If the array is empty the function will output an error message and go back to the menu.*/
/*After after a pointer is assigned to the carsensor class the function uses get methods to output the information*/
void print_all_sensors(class RentalAgency *RentalPlace){
	ofstream outputStream;
	char filename[50];
	/*Check to see if data has been entered from and input file, an error message will display if not.*/
	if (RentalPlace->inventory[0].GetYear() == 0){
		cout << "Error: No data detected" << endl;
	}
	else{
		cout << "Enter the file name: ";
		cin >> filename;
		outputStream.open(filename);
		RentalCar *Car_Ptr = RentalPlace->inventory;
		CarSensor *car_sensor_pt = Car_Ptr->m_sensors;
		cout << "The fleet is currently equipt with:" << endl;
		outputStream << "The fleet is currently equipt with:" << endl;
		cout << "GPS: ";
		outputStream << "GPS: ";
		cout << car_sensor_pt->Getgps() << endl;
		outputStream << car_sensor_pt->Getgps() << endl;
		cout << "Cameras: ";
		outputStream << "Cameras: ";
		cout << car_sensor_pt->Getcamera() << endl;
		outputStream << car_sensor_pt->Getcamera() << endl;
		cout << "Lidars: ";
		outputStream << "Lidars: ";
		cout << car_sensor_pt->Getlidar() << endl;
		outputStream << car_sensor_pt->Getlidar() << endl;
		cout << "Radars: ";
		outputStream << "Radars: ";
		cout << car_sensor_pt->Getradar() << endl;
		outputStream << car_sensor_pt->Getradar() << endl;
	}
}
/*This function takes car information from an array of stucts and outputs the most expensive available car and asks the user if they would like to purchase the car. If yes the program asks for the users name, number of days the would like to rent, and any additional sensors they would like to add.*/
/*If the array is empty the function will output an error message and go back to the menu.*/
/*In order to achive this I used a lot of nested if statement to get user response, my string copy and compare functions to read user responses,and get/set methods to read and output user information.*/
void most_expensive_available(class RentalAgency *RentalPlace){
	int i, j, most_expensive = 0, cost = 0;
	ofstream outputStream;
	char answer[10], name[20], func[10];
	float days;
	char filename[50];
	/*Check to see if data has been entered from and input file, an error message will display if not.*/
	if (RentalPlace->inventory[0].GetYear() == 0){
		cout << "Error: No data detected" << endl;
	}
	else{
		cout << "Enter the file name: ";
		cin >> filename;
		outputStream.open(filename);
		cout << "The most expensive available car is:" << endl;
		RentalCar *Car_Ptr = RentalPlace->inventory;
		RentalCar *Expensive_Ptr = RentalPlace->inventory;
		Car_Ptr++;
		for(;;){
			if(Expensive_Ptr->GetAvailable() == 0){
				Expensive_Ptr++;
				Car_Ptr = RentalPlace->inventory;
			}
			if(Expensive_Ptr->GetAvailable() == 1){
				break;
			}
		}
		for(i=0;i<5;i++,Car_Ptr++){
			if (Car_Ptr->GetBasePrice() > Expensive_Ptr->GetBasePrice() && Car_Ptr->GetAvailable() == 1){
				Expensive_Ptr = Car_Ptr;
			}
		}
		Expensive_Ptr->Print(outputStream);
		cout << endl;
		outputStream << endl;
		for(;;){
			cout << "Would you like to purchase this car (Enter ""yes"" or ""no""): ";
			cin >> answer;
			char *answer_pt = answer;
			char str1[4] = {'y','e','s','\0'};
			char *str1_pt = str1;
			char str2[3] = {'n','o','\0'};
			char *str2_pt = str2;
			if(strcmp(answer_pt, str1_pt)){
				cout << "Enter your name: ";
				cin >> name;
				char *name_pt = name;
				Expensive_Ptr->SetAvailable(0);
				Expensive_Ptr->AddLessee(name_pt);
				cout << "How many days would you like to rent this car: ";
				cin >> days;
				for(;;){
					cout << "Would you like to add aditional functionality (gps, camera, lidar, radar)(Enter ""yes"" or ""no""): ";
					cin >> answer;
					if(strcmp(answer_pt, str1_pt)){
						for(;;){
							bool error = 0;
							CarSensor *car_sensor_pt = Expensive_Ptr->m_sensors;
							int counter = 0;
							for(i=0;i<3;i++,car_sensor_pt++){
									if(car_sensor_pt->GetType(0)!='\0'){
											counter++;
									}
									if(counter==3){
										cout << "Error: car already has maximum amount of sensors." << endl;
										error = 1;
										break;
									}
							}
							if(error==1){
								break;
							}
							cout << "What functionallity would you like: ";
							cin >> func;
							char *func_pt = func;
							char str3[4] = {'g','p','s','\0'};
							char *str3_pt = str3;
							char str4[7] = {'c','a','m','e','r','a','\0'};
							char *str4_pt = str4;
							char str5[6] = {'l','i','d','a','r','\0'};
							char *str5_pt = str5;
							char str6[6] = {'r','a','d','a','r','\0'};
							char *str6_pt = str6;
							if(strcmp(func_pt, str3_pt) || strcmp(func_pt, str4_pt) || strcmp(func_pt, str5_pt) || strcmp(func_pt, str6_pt)){
								car_sensor_pt = Expensive_Ptr->m_sensors;
								for(i=0;i<3;i++,car_sensor_pt++){
										if(car_sensor_pt->CmpSensors(func_pt)){
											cout << "Error: functionallity already equipt." << endl;
											error = 1;
											break;
										}
								}
								if(error==1){
									break;
								}
								char *func_pt = func;
								char str3[4] = {'g','p','s','\0'};
								char *str3_pt = str3;
								char str4[7] = {'c','a','m','e','r','a','\0'};
								char *str4_pt = str4;
								char str5[6] = {'l','i','d','a','r','\0'};
								char *str5_pt = str5;
								char str6[6] = {'r','a','d','a','r','\0'};
								char *str6_pt = str6;
								if(strcmp(func_pt, str3_pt)){
									cost = 5.0;
								}
								else if(strcmp(func_pt, str4_pt)){
									cost = 10.0;
								}
								else if(strcmp(func_pt, str5_pt)){
									cost = 15.0;
								}
								else if(strcmp(func_pt, str6_pt)){
									cost = 20.0;
								}
								func_pt = func;
								Expensive_Ptr->AddCarSensor(func_pt, cost);
								Expensive_Ptr->SetBasePrice(Expensive_Ptr->GetBasePrice(), cost);
								break;
							}
							else{
								cout << "Error: enter a valid functionallity." << endl;
							}
						}
					}
					else if(strcmp(answer_pt, str2_pt)){
						Expensive_Ptr->UpdatePrice(days);
						cout << Expensive_Ptr->GetFinalPrice() << endl;
						cout <<  endl;
						outputStream <<  endl;
						cout << "Congratulations ";
						outputStream << "Congratulations ";
						for(i=0;i<20;i++){
							if(Expensive_Ptr->GetOwner(i) == 0){
								break;
							}
							cout << Expensive_Ptr->GetOwner(i);
							outputStream << Expensive_Ptr->GetOwner(i);
						}
						cout << "! You have sucessfully rented the ";
						outputStream << "! You have sucessfully rented the ";
						cout << Expensive_Ptr->GetTank() << " gallon ";
						outputStream << Expensive_Ptr->GetTank() << " gallon ";
						cout << Expensive_Ptr->GetYear() << " ";
						outputStream << Expensive_Ptr->GetYear() << " ";
						for(i=0;i<10;i++){
							if(Expensive_Ptr->GetMake(i) == 0){
								break;
							}
							cout << Expensive_Ptr->GetMake(i);
							outputStream << Expensive_Ptr->GetMake(i);
						}
						cout << " ";
						outputStream << " ";
						for(i=0;i<10;i++){
							if(Expensive_Ptr->GetModel(i) == 0){
								break;
							}
							cout << Expensive_Ptr->GetModel(i);
							outputStream << Expensive_Ptr->GetModel(i);
						}
						cout << " equipt with: ";
						outputStream << " equipt with: ";
						CarSensor *sensors_pt = Expensive_Ptr->m_sensors;
						for(i=0;i<3;i++,sensors_pt++){
							j=0;
							if(sensors_pt->GetType(j) == 0){
								break;
							}
							for(;j<10;j++){
								if(sensors_pt->GetType(j) == 0){
									break;
								}
								cout << sensors_pt->GetType(j);
								outputStream << sensors_pt->GetType(j);
							}
							cout << " ";
							outputStream << " ";
						}
						cout << "for " << days << " days at a total cost of ";
						outputStream << "for " << days << "days at a total cost of ";
						cout << "$" << Expensive_Ptr->GetFinalPrice() << endl;
						outputStream << "$" << Expensive_Ptr->GetFinalPrice() << endl;

						break;
					}
					else{
						cout << "Error: Enter a valid reply." << endl;
					}
				}
				break;
			}
			else if(strcmp(answer_pt, str2_pt)){
				break;
			}
			else{
				cout << "Error: Enter a valid reply." << endl;
			}
		}
		outputStream.close();
	}
}
