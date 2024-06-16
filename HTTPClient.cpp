#include "HTTPClient.h"

void HTTPClient::Connect(LPCWSTR url, OUT IStream* dataOut)
{
    IStream* stream;
    //Also works with https URL's - unsure about the extent of SSL support though.
    HRESULT result = URLOpenBlockingStream(0, url, &stream, 0, 0);
    if (result != 0)
    {
        return ;
    }
}

template<typename T>
inline T HTTPClient::Get(LPCWSTR param1)
{
    LPWSTR result;
    HRESULT url = CoInternetCombineUrl(HTTP_SERVER_31_URL, param1, NULL, result, NULL, NULL, NULL);

    if (url != 0) {
        return;
    }

    IStream* stream;
    this->Connect(result, &stream);
    char buffer[100];
    unsigned long bytesRead;
    std::stringstream ss;
    stream->Read(buffer, 100, &bytesRead);
    while (bytesRead > 0U)
    {
        ss.write(buffer, (long long)bytesRead);
        stream->Read(buffer, 100, &bytesRead);
    }
    stream->Release();
    std::string resultString = ss.str();
    return T();
}


