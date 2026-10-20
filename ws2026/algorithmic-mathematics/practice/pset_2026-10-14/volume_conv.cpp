#include <iostream>

// Sollten wirklich `const` sein, aber IST JA NICHT ERLAUBT
double cubic_inch_per_gallon = 231.0;
double cm_per_inch = 2.54;
// Wir duerfen ja auch nicht `pow` von `cmath` benutzen...
double ml_per_cubic_inch = cm_per_inch * cm_per_inch * cm_per_inch;
double ml_per_gallon = cubic_inch_per_gallon * ml_per_cubic_inch;
double litre_per_gallon = ml_per_gallon / 1000;

int main(void) {
  std::cout << "Enter gallons to convert: \n> ";

  double gallons;
  // SAFETY: Welche Sicherheit?
  // Wir haben nicht einmal Semikolons als erlaubte
  // Sprachelemente, geschweige denn ein Turing complete
  // Subset an erlaubten Sprachelementen die eine
  // Inputverifikation erlauben wuerden.
  //
  // Wenn eine ungueltige Eingabe erfolgt,
  // wird anstelle eines Fehlers einfach die 0 reingeschrieben. WTF?
  std::cin >> gallons;

  // Sollte auch const sein, aber once again
  // duerfen wir das ja nicht benutzen AAAAAAAAAAAAAAAAAAA
  double litres = gallons * litre_per_gallon;
  std::cout << gallons << "gal = " << litres << "l" << std::endl;

  return 0;
}
