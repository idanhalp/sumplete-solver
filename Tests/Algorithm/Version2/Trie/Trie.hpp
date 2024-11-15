#ifndef TESTS_TRIE_HPP
#define TESTS_TRIE_HPP

#include "Source/Backend/Algorithm/Version2/Utils/Trie/Trie.hpp"
#include <QObject>
#include <QtTest>
#include <vector>

class TrieTests : public QObject
{
	Q_OBJECT

private slots:
	auto initTestCase() -> void;
	auto test_1() const -> void;
	auto test_2() const -> void;
	auto test_3() const -> void;
	auto test_4() const -> void;
	auto test_5() const -> void;
	auto test_6() const -> void;

private:
	Algorithm::Version2::Utils::Trie trie;
	std::vector<bool> sequence_1;
	std::vector<bool> sequence_2;
};

#endif // TESTS_TRIE_HPP
