bool ChatSpam = false;

monoString *(*CreateString)(void *_this, const char *str);
void (*get_StringInstance);

void (*SendChatMessage)(void *instance, monoString *message);;
void(* old_Chatv1)(void * instance);
void Chatv1(void*instance) {
    if(instance != NULL ) {
       if(ChatSpam) {
		   ChatSpam = true;
           SendChatMessage(instance,CreateString(get_StringInstance,"Test"));	   
       }
    }
    old_Chatv1(instance);
}

HOOK_LIB("libil2cpp.so", "Offset", Chatv1, old_Chatv1); 
    
SendChatMessage = (void (*)(void *,monoString *))getAbsoluteAddress(targetLibName, Offset);
                   
CreateString = (monoString*(*)(void *,const char *))getAbsoluteAddress(targetLibName, Offset);
    
get_StringInstance  = (void (*))getAbsoluteAddress(targetLibName,Offset);


case 0:
     ChatSpam = boolean;
     break;
