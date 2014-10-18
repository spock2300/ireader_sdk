#ifndef _http_server_internal_h_
#define _http_server_internal_h_

#include "aio-tcp-transport.h"
#include "http-server.h"

struct http_session_t
{
	struct http_server_t *server;

	void* session;
	void* parser;

	char data[2 * 1024];

	// send buffer vector
	int vec_count;
	socket_bufvec_t *vec;
	socket_bufvec_t vec3[3];
};

struct http_server_t
{
	void* transport;

	http_server_handler handle;
	void* param;
};

void* http_session_onconnected(void* ptr, void* session, const char* ip, int port);
void http_session_ondisconnected(void* param);
void http_session_onsend(void* param, int code, size_t bytes);
void http_session_onrecv(void* param, const void* msg, size_t bytes);

#endif /* !_http_server_internal_h_ */