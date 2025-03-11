#include <iostream>
#include <string>

using namespace std;

int main()
{
	string man_fav1, man_fav2, man_fav3;
	string woman_fav1, woman_fav2, woman_fav3;

	cin >> man_fav1 >> man_fav2 >> man_fav3;
	cin >> woman_fav1 >> woman_fav2 >> woman_fav3;

	int num_restaurants;
	cin >> num_restaurants;

	for (int restaurant = 0; restaurant < num_restaurants; restaurant++)
	{
		string restaurant_name;
		int menu_size;

		cin >> restaurant_name >> menu_size;

		int man_has_dish = 0;
		int woman_count = 0;

		for (int item = 0; item < menu_size; item++) 
		{
			string dish;
			cin >> dish;

			if (dish == man_fav1 || dish == man_fav2 || dish == man_fav3) {
				man_has_dish++;
			}

			if (dish == woman_fav1 || dish == woman_fav2 || dish == woman_fav3) {
				woman_count++;
			}
		}

		if (man_has_dish >= 1 && woman_count >= 2) 
		{
			cout << restaurant_name << endl;
			cout << "Huray! I won't have to watch The Bachelor today!" << endl;
			return 0;
		}
	}

	cout << "Oh no.. this night the couch will be my bro" << endl;
	return 0;
		
}

