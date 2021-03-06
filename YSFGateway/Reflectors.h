/*
*   Copyright (C) 2016,2017 by Jonathan Naylor G4KLX
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program; if not, write to the Free Software
*   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#if !defined(Reflectors_H)
#define	Reflectors_H

#include "UDPSocket.h"
#include "Timer.h"

#include <vector>
#include <string>

class CYSFReflector {
public:
	CYSFReflector() :
	m_id(),
	m_name(),
	m_desc(),
	m_count("000"),
	m_address(),
	m_port(0U)
	{
	}

	std::string  m_id;
	std::string  m_name;
	std::string  m_desc;
	std::string  m_count;
	in_addr      m_address;
	unsigned int m_port;
};

class CReflectors {
public:
	CReflectors(const std::string& hostsFile, unsigned int reloadTime);
	~CReflectors();

	void setParrot(const std::string& address, unsigned int port);	
	void setYSF2DMR(const std::string& address, unsigned int port);

	bool load();

	CYSFReflector* find(const std::string& id);

	std::vector<CYSFReflector*>& current();

	std::vector<CYSFReflector*>& search(const std::string& name);

	bool reload();

	void clock(unsigned int ms);

private:
	std::string                 m_hostsFile;
	std::string                 m_parrotAddress;
	unsigned int                m_parrotPort;
	std::string                 m_YSF2DMRAddress;
	unsigned int                m_YSF2DMRPort;
	std::vector<CYSFReflector*> m_newReflectors;
	std::vector<CYSFReflector*> m_currReflectors;
	std::vector<CYSFReflector*> m_search;
	CTimer                      m_timer;
};

#endif
