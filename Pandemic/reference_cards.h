#pragma once
class reference_cards
{
public:
	void output();
	static reference_cards* instance();
protected:
	reference_cards();
	static reference_cards *s_instance;
};

