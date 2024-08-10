#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Gun {

private:
	int bullet;
public:
	Gun(int bullet) : bullet(bullet) { }

	Gun(Gun &gun) : bullet(gun.bullet) {}

	void Shot() {
		cout << "BBANG!" << endl;
		bullet--;
	}

	int getBullet() {
		return bullet;
	}

};

class Police {
private:
	int handcuffs; //¼ÒÀ¯ ¼ö°©¼ö
	Gun *pistol; // ¼ÒÀ¯ ±ÇÃÑ

public:
	Police(int bullet, int handcuffs) : handcuffs(handcuffs) {
		if (bullet > 0) {
			pistol = new Gun(bullet);
		}
		else {
			pistol = NULL;
		}
	}

	Police(Police &police) : handcuffs(police.handcuffs){
		
		if (police.pistol != NULL) {
			pistol = new Gun(*(police.pistol));
		}
		else {
			pistol = NULL;
		}
	}

	// police2.operator=(police1);
	// police2 = police1;
	Police &operator=(Police &copy) {

		if (pistol != NULL) {
			delete pistol;
		}

		if (copy.pistol != NULL) {
			pistol = new Gun(*(copy.pistol));
		}
		else {
			pistol = NULL;
		}

		handcuffs = copy.handcuffs;


		return *this;
	}


	void PutHandCuff() {
		cout << "SNAP!" << endl;
		handcuffs--;
	}

	void Shot() {
		if (pistol == NULL) {
			cout << "Hut BBANG!" << endl;
		}
		else {
			pistol->Shot();
		}
	}

	void Showinfo() {
		cout << "handcuffs : " << handcuffs << endl;
		cout << "bullet : " << pistol->getBullet() << endl;
	}

	~Police() {
		if(pistol != NULL)
		delete pistol;
	}

};

int main() {

	Police p1(10, 2);
	p1.Showinfo();
	Police p2(20, 1);
	p2.Showinfo();
	p1 = p2;
	p1.Showinfo();

	Police p3 = p2;
	p3.Showinfo();

	return 0;
}