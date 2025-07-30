class Encounter {
 public:
  Encounter()
  : A{new Monster()},
    B{new Monster()},
    C{new Monster()} {}

  ~Encounter() {
    // The Monster type uses RAII so they'll delete their
    // Image resources - we don't need to worry about it here
    delete A;
    delete B;
    delete C;
  }

  Monster* A{nullptr};
  Monster* B{nullptr};
  Monster* C{nullptr};
}