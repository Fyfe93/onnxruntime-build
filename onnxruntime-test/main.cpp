#include <onnxruntime_training_cxx_api.h>
#include <iostream>

int main() {
    try {
        // Create environment
        Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "onnxruntime_test");
        
        // Create session options
        Ort::SessionOptions session_options;
        session_options.SetIntraOpNumThreads(1);
        
        // Create session
        // Ort::Session session(env, "dummy.onnx", session_options);

        Ort::CheckpointState checkpoint_state = Ort::CheckpointState::LoadCheckpoint(".");

        
        std::cout << "Successfully linked to ONNX Runtime!" << std::endl;
        return 0;
    }
    catch (const Ort::Exception& e) {
        std::cerr << "ONNX Runtime error: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
} 