#include "gtest/gtest.h"
#include "../../Lista/Lista.h"

Lista<int> *l1;

TEST(test_Lista, nuevaListaTamanioCero) {
    l1 = new Lista<int>();
    EXPECT_EQ(l1->getTamanio(), 0);
    EXPECT_EQ(l1->esVacia(), true);
}

TEST(test_Lista, agregoTres_getTamanio) {
    l1->insertarPrimero(3);
    EXPECT_EQ(l1->getTamanio(), 1);
    l1->insertarPrimero(2);
    EXPECT_EQ(l1->getTamanio(), 2);
    l1->insertarPrimero(1);
    EXPECT_EQ(l1->getTamanio(), 3);
}

TEST(test_Lista, getDato) {
    EXPECT_EQ(l1->getDato(0), 1);
    EXPECT_EQ(l1->getDato(1), 2);
    EXPECT_EQ(l1->getDato(2), 3);
}

TEST(test_Lista, insertarUltimo) {
    l1->insertarUltimo(200);
    EXPECT_EQ(l1->getDato(3), 200);
    l1->insertarUltimo(300);
    EXPECT_EQ(l1->getDato(4), 300);
}

TEST(test_Lista, insertar) {
    l1->insertar(1, 321);
    EXPECT_EQ(l1->getDato(1), 321);
    l1->insertar(1, 123);
    EXPECT_EQ(l1->getDato(1), 123);
    EXPECT_EQ(l1->getDato(2), 321);
}

TEST(test_Lista, remover) {
    l1->remover(1);
    EXPECT_EQ(l1->getDato(1), 321);
    l1->remover(1);
    EXPECT_EQ(l1->getDato(1), 2);
}

TEST(test_Lista, reemplazar) {
    l1->reemplazar(1, 300);
    EXPECT_EQ(l1->getDato(1), 300);
    l1->reemplazar(1, 456);
    EXPECT_EQ(l1->getDato(1), 456);
}

TEST(test_Lista, vaciar) {
    l1->vaciar();
    EXPECT_EQ(l1->esVacia(), true);
    EXPECT_EQ(l1->getTamanio(), 0);
}

TEST(test_Lista, getDato_fueraDeRango) {
    l1->insertarPrimero(3);
    EXPECT_ANY_THROW(l1->getDato(10));
}

TEST(test_Lista, remover_fueraDeRango) {
    l1->insertarPrimero(3);
    EXPECT_ANY_THROW(l1->remover(10));
}
