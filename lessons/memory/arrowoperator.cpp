void Combat(Monster* Enemy){
	// Annoying
    (*Enemy).TakeDamage(50);
    // Better
  	Enemy->TakeDamage(50);
}
