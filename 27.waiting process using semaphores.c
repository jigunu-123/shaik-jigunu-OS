import threading

class Semaphore:
    def _init_(self, initial_instances):
        self.lock = threading.Lock()
        self.instances = initial_instances

    def acquire(self):
        with self.lock:
            if self.instances > 0:
                self.instances -= 1
                return True
            else:
                return False

    def release(self):
        with self.lock:
            self.instances += 1

def process(semaphore):
    print("Process is waiting to acquire the semaphore...")
    acquired = semaphore.acquire()
    if acquired:
        print("Semaphore acquired. Signaling the waiting process...")
        # Perform some operations or tasks
        print("Semaphore released.")
        semaphore.release()
    else:
        print("Semaphore is not available. Waiting for it to be released...")

def main():
    num_instances = 4
    semaphore = Semaphore(num_instances)
    processes = []

    # Create multiple threads representing processes
    for _ in range(num_instances + 2):  # Creating more processes than semaphore instances to test waiting
        process_thread = threading.Thread(target=process, args=(semaphore,))
        processes.append(process_thread)
        process_thread.start()

    # Wait for all threads to complete
    for process_thread in processes:
        process_thread.join()

if _name_ == "_main_":
    main()
