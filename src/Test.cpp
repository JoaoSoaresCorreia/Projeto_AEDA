#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "Hotel.h"

void test_criacao_quarto() {
	Simples s1("frente");
	Simples s2("traseiras");
	Duplo d1("frente");
	Duplo d2("traseiras");
	Duplo d3("traseiras");

	ASSERT_EQUAL("frente", s1.get_location());
	ASSERT_EQUAL("frente", d1.get_location());
	ASSERT_EQUAL("traseiras", s2.get_location());
	ASSERT_EQUAL("traseiras", d2.get_location());
	ASSERT_EQUAL(0, s1.get_base_price());
	ASSERT_EQUAL(0, s1.get_cost());
	ASSERT_EQUAL(0, d1.get_base_price());
	ASSERT_EQUAL(0, d1.get_cost());
	ASSERT_EQUAL(1, s1.get_id());
	ASSERT_EQUAL(1, d1.get_id());
	ASSERT_EQUAL(2, s2.get_id());
	ASSERT_EQUAL(2, d2.get_id());
	ASSERT_EQUAL(3, d3.get_id());

}

void test_criacao_hote_e_quarto() {
	Hotel h;
	Simples s3("frente");
	Simples s4("traseiras");
	Duplo d4("frente");
	Duplo d5("traseiras");
	Duplo d6("traseiras");
	h.set_quarto_base_price(300);
	h.set_quarto_frente_tax(0.05);
	h.set_quarto_tras_tax(0.02);
	h.add_quarto(&s3);
	h.add_quarto(&s4);
	h.add_quarto(&d4);
	h.add_quarto(&d5);
	h.add_quarto(&d6);

	h.update_quartos_tax();
	ASSERT_EQUAL(5, h.get_quartos().size());
	ASSERT_EQUAL((float)0.05, (float)h.get_quartos()[0]->get_tax());
	ASSERT_EQUAL((float)0.02, (float)h.get_quartos()[1]->get_tax());

	ASSERT_EQUAL(315, h.get_quartos()[0]->get_cost());
	ASSERT_EQUAL(306, h.get_quartos()[1]->get_cost());

}

void runSuite() {
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(test_criacao_quarto));
	s.push_back(CUTE(test_criacao_hote_e_quarto));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main() {
	runSuite();
	return 0;
}

