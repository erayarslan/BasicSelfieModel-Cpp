/**
 * @module BasicSelfieModel
 * author eray arslan
 * inspired by @ahmetozantekin BasicSelfieModel
 * src https://github.com/ahmetozantekin/BasicSelfieModel
 */

#include <iostream>

#define male 0
#define female 1

struct Instagram {
  Instagram (int gender) {
    this->barzoCount = 50;
    this->gender = gender;
    this->areYouFamous = false;
    this->like = 0;
  }

  void setAreYouFamous (bool areYouFamous) {
    this->areYouFamous = areYouFamous;
  }

  const char * profile () {
    return this->areYouFamous ? "sexy" : "barzo";
  }

  int barzoCount;
  int gender;
  bool areYouFamous;
  int like;
};

struct Selfie : Instagram {
  Selfie (int gender) : Instagram (gender) {
    this->showBoobs = false;
  }

  void takePhoto (bool showBoobs) {
    this->showBoobs = showBoobs;

    if (showBoobs) {
      this->setAreYouFamous(true);
    }

    if (this->gender == male && !this->areYouFamous) {
      this->like = 7;
    } else if (this->gender == male && this->areYouFamous) {
      this->like = 300 - this->barzoCount;
    } else if (this->gender == female) {
      if (!this->areYouFamous) {
        this->like = 20; // bff mode #on
      } else if (this->areYouFamous) {
        this->like = 700;
      }

      while (this->showBoobs && this->barzoCount < 150) {
        this->like += this->barzoCount;
        this->barzoCount++;
      }
    } else {
      std::cerr << "Go away fuckin faggot." << std::endl;
    }
  }

  bool showBoobs;
};

int main () {
  Selfie ayca(female);
  ayca.takePhoto(true);

  std::cout << ayca.profile() << std::endl;
}
