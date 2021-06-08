#pragma once

#include "websrv.h"

class Request;

class Response
{
private:
	unsigned int _status;
	std::string _name;
	std::string _ctype;
	std::string _clen;
	std::string _body;
	std::string _resp;
	Request _request;

	std::string getCodeStatus();

	void methodGet();
	void methodPost();
	void methodDelete();

	void checkFilePermission(std::string &, int);
	void deleteFile(std::string &);
	void readFile(std::string &);
	void uploadFile();

	std::string getFilePath(std::string);
	std::string getCurrentDirectory();
	void makeBody();

public:
	Response();
	Response(Request);
	~Response();

	void makeResponse();
	void setRequest(Request);

	unsigned int getStatus() const;
	const std::string &getName() const;
	const std::string &getContentType() const;
	const std::string &getContentLength() const;
	const std::string &getBody() const;
	const std::string &getResponse() const;

	class NotFound : public std::exception
	{
		virtual const char *what() const throw();
	};

	class NotImplemented : public std::exception
	{
		virtual const char *what() const throw();
	};

	class MethodNotAllowed : public std::exception
	{
		virtual const char *what() const throw();
	};

	class Forbidden : public std::exception
	{
		virtual const char *what() const throw();
	};
};