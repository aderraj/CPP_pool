#include "Account.hpp"
#include <iostream>
#include <iomanip>

Account::Account(int initial_deposit)
  : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
		_nbAccounts++;
		_totalAmount += initial_deposit;
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";"\
		<< "amount:" << _amount << ";"\
		<< "created" << std::endl;

}

Account::~Account() {

		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";"\
		<< "amount:" << _amount << ";"\
		<< "closed" << std::endl;

}

void	Account::displayAccountsInfos( void) {

	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";"\
	<< "total:" << _totalAmount << ";"\
	<< "deposits:" << _totalNbDeposits << ";"\
	<< "withdrawals:" << _totalNbWithdrawals << std::endl;

}

void  Account::_displayTimestamp( void ) {

	time_t	k_time = time(0);
	tm			*date = localtime(&k_time);

	std::cout << "["\
	<< 1900 + date->tm_year\
	<< std::setw(2) << std::setfill('0') << 1+ date->tm_mon\
	<< std::setw(2) << std::setfill('0') << date->tm_mday\
	<< "_"\
	<< std::setw(2) << std::setfill('0') << date->tm_hour\
	<< std::setw(2) << std::setfill('0') << date->tm_min\
	<< std::setw(2) << std::setfill('0') << date->tm_sec\
	<< "]";

}

void	Account::displayStatus( void ) const {

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"\
	<< "amount:" << _amount << ";"\
	<< "deposits:" << _nbDeposits << ";"\
	<< "withdrawals:" << _nbWithdrawals << std::endl;

}

void	Account::makeDeposit( int deposit ) {

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"\
	<< "p_amount:" << _amount << ";"\
	<< "deposit:" << deposit << ";"\
	<< "amount:" << _amount + deposit << ";"\
	<< "nb_deposits:" << ++_nbDeposits << std::endl;
	_amount += deposit;
	_totalNbDeposits++;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"\
	<< "p_amount:" << _amount << ";"\
	<< "withdrawal:";

	if (withdrawal > _amount) {
		std::cout << "refused" << std::endl;
		return (false);
	}

	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout << withdrawal << ";"\
	<< "amount:" << _amount << ";"\
	<< "nb_withdrawals:" << _nbWithdrawals << std::endl;

	return (true);

}

int	Account::checkAmount( void ) const { return (_amount); }

int Account::getNbAccounts( void ) { return _nbAccounts; }

int Account::getTotalAmount( void ) { return _totalAmount; }

int Account::getNbDeposits( void ) { return _totalNbDeposits; }

int Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }


