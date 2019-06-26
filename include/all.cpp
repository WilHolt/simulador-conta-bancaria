#define CATCH_CONFIG_MAIN  // Faz com o que o catch gere o main
#include "catch.hpp"
#include "conta.h"
#include "common.h"
#include <memory>


TEST_CASE("TESTES DE TRANSFERENCIA", "[Transferir 100]") {
    SECTION( "transferencia de valor valido" ) {
    auto conta1 = std::make_shared("wilder", "01", "200");
	auto conta2 = std::make_shared("wilder", "02", "200");
    conta1->transferencia(conta1,conta2,300);
    double valor = conta2->getSaldo();
    REQUIRE( valor == 200);
    }
        SECTION( "transferencia de valor invalido" ) {
    auto conta1 = std::make_shared("wilder", "01", "200");
	auto conta2 = std::make_shared("wilder", "02", "200");
    conta1->transferencia(conta1,conta2,100);
    double valor = conta2->getSaldo();
    REQUIRE( valor == 300);
    }
}

TEST_CASE("TESTES DE SAQUE", "[Sacar 100]") {
    SECTION( "Saque de valor " ) {
        auto conta2 = std::make_shared("wilder", "02", "200");
        conta2->saque(100)
        double valor = conta2->getSaldo();
        REQUIRE(valor == 100);
    }
}
TEST_CASE("TESTES DE DEPÓSITO", "[Sacar 1000]") {
      SECTION( "Deposito de valor " ) {
        auto conta2 = std::make_shared("wilder", "02", "200");
        conta2->deposito(100)
        double valor = conta2->getSaldo();
        REQUIRE(valor == 100);
    }
}