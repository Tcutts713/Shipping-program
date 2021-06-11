// Shipping_program.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program will take the input from the user about the item they are shipping, where they are shipping too,
// what their order total is and calculate the shipping cost to either USA, CAN, or AUS.
// Each location has four different costs per order total and will add in fragile shipping costs, $2.
// Programming assignment 3  ITCS 2530   TIM CUTTS Modified for GITHUB submission.

#include <iostream> //to use inputs and outputs
#include <iomanip> //to use setfill and setw
#include <string>  //to use strings
#include <algorithm> //to use transform
#include <fstream> //to write and to read from files

using namespace std; //used so we don't have to type std all the time

const double US_SHIPPING_ONE = 6; //constant variables for shipping prices to the USA 
const double US_SHIPPING_TWO = 9; //constant variables for shipping prices to the USA 
const double US_SHIPPING_THREE = 12; //constant variables for shipping prices to the USA 

const double CA_SHIPPING_ONE = 8; //constant variables for shipping prices to Canada 
const double CA_SHIPPING_TWO = 12; //constant variables for shipping prices to Canada 
const double CA_SHIPPING_THREE = 15; //constant variables for shipping prices to Canada 

const double AUS_SHIPPING_ONE = 10; //constant variables for shipping prices to Australia 
const double AUS_SHIPPING_TWO = 14; //constant variables for shipping prices to Australia 
const double AUS_SHIPPING_THREE = 17; //constant variables for shipping prices to Australia 

const double MARS_SHIPPING_ONE = 900; //constant variable for shipping prices to Mars
const double MARS_SHIPPING_TWO = 1200; //constant variable for shipping prices to Mars
const double MARS_SHIPPING_THREE = 1600; //constant variable for shipping prices to Mars

const double FREE_SHIPPING = 0; //constant variable for free shipping

const double FRAGILE = 2; //constant variable for shipping cost if item is fragile

const int USA = 1; //constant variable for location code to switch from string to int
const int CA = 2; //constant variable for location code to switch from string to int
const int AUS = 3; //constant variable for location code to switch from string to int
const int MARS = 4; //constant variable for location code to switch from string to int


int main()
{
	double order_total; //variable needed for getting the order total from the user
	double total_shipping = 0; //variable needed to get total shipping to the user set at 0 to use for math
	int destination_code = 0; //variable needed to set destination code.  Set at 0 to change value later

	char frag; //variable for getting y, Y, n, N from user if item is fragile or not
	string destination; //variable to get the destination from the user
	string item_name; //variable to get the item name from the user

	fstream order; //variable to declare file name
	


	cout << setw(50) << setfill('.') << "" << endl; //this line outputs 50 .'s to the screen
	cout << " ITCS 2530 - Programming Assignment for week #3" << endl; //welcome message to the screen
	cout << setw(50) << setfill('.') << "" << endl; //this line outputs 50 .'s to the screen
	cout << "\n" << "\n" << endl; //creates two blank line spaces

	cout << left; //sets the justification to the left
	cout << setw(50) << setfill('.') << "Please enter the item name (no spaces)"; //sets the width and fills the empty spaces with '.' also asks the user for the item name
	cin >> item_name; //input line for item name
	

	cout << left; //sets the justification to the left
	cout << setw(50) << setfill('.') << "Is the item fragile? (y=yes/n=no)"; //sets the width and fills the empty spaces with '.' also asks the user if the item is fragile or not
	cin >> frag; //input line for fragile answer
	
	switch (frag) //starts a switch for fragile variable
	{
	case 'y': 
	case 'Y':
		total_shipping = total_shipping + FRAGILE; //if answer is either y or Y the switch stops here and adds 2 to the shipping total
		break;

	case 'n':
	case 'N':
		total_shipping = total_shipping; //if answer is either n or N the switch stops here and just defaults the shipping total to its current state
		break;

	default:
		cout << "\n"; // create new line space
		cout << "invalid entry, exiting" << endl; //if the answer is neither y, Y, n, N the switch stops here and stops the program while printing to the screen invalid entry, exiting
		return 0;
	}

	

	cout << left; //sets the justification to the left
	cout << setw(50) << setfill('.') << "Please enter your order total"; //sets the width and fills the empty spaces with '.' also asks the user for their order total
	cin >> order_total; //input line for order total
	

	cout << left; //sets the justification to the left
	cout << setw(50) << setfill('.') << "Please enter destination. (usa/can/aus/mars)"; //sets the width and fills the empty spaces with '.' also asks the user for the destination
	cin >> destination; //input line for destination
	

	if (destination == "usa" || destination == "USA")  //if structure to convert the users input of the location and change it to a destination code varible for switch structure below
		destination_code = USA;							//can check and convert usa, USA, can, CAN, aus, and AUS within this structure using == (equal to) and || (or) 
	else if (destination == "can" || destination == "CAN")
		destination_code = CA;
	else if (destination == "aus" || destination == "AUS")
		destination_code = AUS;
	else if (destination == "mars" || destination == "MARS")
		destination_code = MARS;
		
	switch (destination_code)  //switch structure to take destination code and add up the total shipping costs
	{
	case 1:  //if destination code is 1 switch stops here

		if (order_total <= 50)  //if structure to calculate the total shipping.  Checking if the order total is less than or equal to 50
			total_shipping = total_shipping + US_SHIPPING_ONE;  //this line is the current total shipping + 6
		else if (order_total > 50 && order_total <= 100) //Checking if the order total is more than 50 and less than or equal to 100
			total_shipping = total_shipping + US_SHIPPING_TWO; //this line is the current total shipping + 9
		else if (order_total > 100 && order_total <= 150) //Checking if the order total is more than 100 and less than or equal to 150
			total_shipping = total_shipping + US_SHIPPING_THREE; //this line is the current total shipping + 12
		else //if the order total is more than 150 shipping is free
			total_shipping = total_shipping + FREE_SHIPPING; //this line is the current total shipping + 0
		break; //to break out of switch structure

	case 2: //if destination code is 2 switch stops here


		if (order_total <= 50) //if structure to calculate the total shipping.  Checking if the order total is less than or equal to 50
			total_shipping = total_shipping + CA_SHIPPING_ONE; //this line is the current total shipping + 8
		else if (order_total > 50 && order_total <= 100) //Checking if the order total is more than 50 and less than or equal to 100
			total_shipping = total_shipping + CA_SHIPPING_TWO; //this line is the current total shipping + 12
		else if (order_total > 100 && order_total <= 150) //Checking if the order total is more than 100 and less than or equal to 150
			total_shipping = total_shipping + CA_SHIPPING_THREE; //this line is the current total shipping + 15
		else
			total_shipping = total_shipping + FREE_SHIPPING; //this line is the current total shipping + 0
		break; //to break out of switch structure

	case 3: //if destination code is 2 switch stops here

		if (order_total <= 50) //if structure to calculate the total shipping.  Checking if the order total is less than or equal to 50
			total_shipping = total_shipping + AUS_SHIPPING_ONE; //this line is the current total shipping + 10
		else if (order_total > 50 && order_total <= 100) //Checking if the order total is more than 50 and less than or equal to 100
			total_shipping = total_shipping + AUS_SHIPPING_TWO; //this line is the current total shipping + 14
		else if (order_total > 100 && order_total <= 150) //Checking if the order total is more than 100 and less than or equal to 150
			total_shipping = total_shipping + AUS_SHIPPING_THREE; //this line is the current total shipping + 17
		else
			total_shipping = total_shipping + FREE_SHIPPING;  //this line is the current total shipping + 0
		break; //to break out of switch structure

	case 4: //if destination code is 2 switch stops here

		if (order_total <= 50) //if structure to calculate the total shipping.  Checking if the order total is less than or equal to 50
			total_shipping = total_shipping + MARS_SHIPPING_ONE; //this line is the current total shipping + 10
		else if (order_total > 50 && order_total <= 100) //Checking if the order total is more than 50 and less than or equal to 100
			total_shipping = total_shipping + MARS_SHIPPING_TWO; //this line is the current total shipping + 14
		else if (order_total > 100 && order_total <= 150) //Checking if the order total is more than 100 and less than or equal to 150
			total_shipping = total_shipping + MARS_SHIPPING_THREE; //this line is the current total shipping + 17
		else
			total_shipping = total_shipping + FREE_SHIPPING;  //this line is the current total shipping + 0
		break; //to break out of switch structure

	default:
		cout << "\n"; //creates a new line space
		cout << "invalid entry, exiting" << endl; //if the destination code is neither 1, 2, or 3 the switch defaults to here and ends the program with invalid entry, exiting to the screen
		return 0;

	}


	cout << "\n"; //creates a new line space

	cout << fixed << showpoint << setprecision(2); //sets the decimal to show and to two places
	cout << left; //sets the justification to the left
	cout << setw(41) << setfill('.') << "Your item is"; //sets the width and fills empty space with '.' with the output of your item is
	transform(item_name.begin(), item_name.end(), item_name.begin(), ::toupper); //this line transforms the users original input and makes it all uppercase 
	cout << item_name << endl; //outputs the item name now in uppercase

	cout << left; //sets the justification to the left
	cout << setw(41) << setfill('.') << "Your shipping cost is" << "$" << total_shipping << endl; //sets the width and fills empty space with '.' with the output of your shipping cost is $

	cout << left; //sets the justification to the left
	cout << setw(41) << setfill('.') << "You are shipping to"; //sets the width and fills empty space with '.' with the output of you are shipping to
	transform(destination.begin(), destination.end(), destination.begin(), ::toupper); //this line transforms the users original input and makes it all uppercase
	cout << destination << endl; //outputs the destination now in uppercase

	cout << left; //sets the justification to the left
	cout << setw(41) << setfill('.') << "Your total shipping costs are" << "$" << total_shipping + order_total << endl;  //sets the width and fills empty space with '.' with the output of your total shipping costs are $ while adding the current total shipping with order total

	cout << "\n"; //creates a new line space
	cout << right; //sets the justification to the right
	cout << setw(41) << setfill('.') << "Thank You!"; //sets the width and fills the empty spaces  with '.' and outputs Thank you

	order.open("order.txt", ios::out); //this line begins to open the order.txt file
	if (order.is_open()) { //this line checks to see if order.txt and if so begins to write the following lines to the file
		//The lines 192 through 213 are the exact same as lines 169 through 188.  
		//The only difference is cout is changed to order variable to be able to write to the order.txt
		order << fixed << showpoint << setprecision(2);
		order << left;
		order << setw(41) << setfill('.') << "Your item is";
		transform(item_name.begin(), item_name.end(), item_name.begin(), ::toupper);
		order << item_name << endl;

		order << left;
		order << setw(41) << setfill('.') << "Your shipping cost is" << "$" << total_shipping << endl;

		order << left;
		order << setw(41) << setfill('.') << "You are shipping to";
		transform(destination.begin(), destination.end(), destination.begin(), ::toupper);
		order << destination << endl;

		order << left;
		order << setw(41) << setfill('.') << "Your total shipping costs are" << "$" << total_shipping + order_total << endl;

		order << "\n";
		order << right;
		order << setw(41) << setfill('.') << "Thank You!";

		order.close(); //this line closes the order.txt file so no further information is written to it.
	}
	return 0;
}

