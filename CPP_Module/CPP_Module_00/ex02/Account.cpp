/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:17:52 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/28 23:23:20 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account()
{
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbDeposits = 0;
	_totalAmount += initial_deposit;
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "created\n";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "closed\n";
	_totalAmount -= _amount;
	_nbAccounts--;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ';';
	std::cout << "total:" << _totalAmount << ';';
	std::cout << "deposits:" << _totalNbDeposits << ';';
	std::cout << "withdrawals:" << _totalNbWithdrawals << '\n';
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" << _amount << ';';
	std::cout << "deposit:";
	_amount += deposit;
	if (!checkAmount()) {
		_amount -= deposit;
		return ;
	}
	std::cout << deposit << ';';
	std::cout << "amount:" << _amount << ';';
	_nbDeposits++;
	std::cout << "nb_deposits:" << _nbDeposits << '\n';
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" << _amount << ';';
	std::cout << "withdrawal:";
	_amount -= withdrawal;
	if (!checkAmount()) {
		_amount += withdrawal;
		return (false);
	}
	std::cout << withdrawal << ';';
	std::cout << "amount:" << _amount << ';';
	_nbWithdrawals++;
	std::cout << "nb_withdrawals:" << _nbWithdrawals << '\n';
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}

int Account::checkAmount(void) const
{
	if (_amount >= 0) return (1);
	else {
		std::cout << "refused\n";
		return (0);
	}
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "deposits:" << _nbDeposits << ';';
	std::cout << "withdrawals:" << _nbWithdrawals << '\n';
}

void Account::_displayTimestamp(void)
{
	std::time_t t = std::time(NULL);
	if (t == (time_t)(-1))
	{
		std::cout << "ERROR : time()\n";
		exit(EXIT_FAILURE);
	}
	char timestamp[16];
	if (std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", localtime(&t)) == 0) {
		std::cout << "ERROR : time()\n";
		exit(EXIT_FAILURE);
	}
	std::cout << '[' << timestamp << ']' << ' ';
}