class IOWrapper{
    private:
    handle_t obj;
    public:
    IOWrapper() = delete;
    IOWrapper(handle_t obj): obj(obj) { }
    IOWrapper(IOWrapper const &other) = delete;
    IOWrapper operator=(IOWrapper const &other) = delete;

    IOWrapper(IOWrapper &&other): obj(other.obj){
        other.obj = kNullHandle;
    }

    IOWrapper& operator=(IOWrapper &&other){
        if(&other == this){
            return *this;
        }
        if(obj != kNullHandle){
            raw_close(obj);
        }
        obj = other.obj;
        if(other.obj != kNullHandle){
            other.obj = kNullHandle;
        }
        return *this;
    }

    void Write(const std::string &content){
        if(obj != kNullHandle){
            raw_write(obj, content);
        }
    }

    ~IOWrapper(){
        if(obj != kNullHandle){
            raw_close(obj);
        }
    }
};