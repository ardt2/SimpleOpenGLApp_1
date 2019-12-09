#ifndef _MY_OPENGLAPP_1_EXCEPTIONS_HPP_
#define _MY_OPENGLAPP_1_EXCEPTIONS_HPP_
// ============================================================================


// ============================================================================
inline std::string TrimPath(std::string path) // inline - чтобы линковщик не ругался.
{
	size_t pos = path.find_last_of('\\', path.length());
	size_t n = path.length() - pos;

	path = path.substr(pos + 1, n - 1);
	return path;
}

// ------------------------------------------------------------------
class TException
{
public:
	std::string File;
	int Line;
	std::string Caption;
	std::string Text;

	TException(const std::string& file, int line,
		const std::string& text, const std::string& caption)
		: Line(line), Caption(caption)
	{
		size_t pos = file.find_last_of('\\', file.length());
		// Проверку pos == max size_t
		if (pos > 100000)
		{
			File = file; // std::move
		}
		else
		{
			size_t n = file.length() - pos;
			File = file.substr(pos + 1, n - 1);
		}

		Text = "In \"" + File + "\" at line " + std::to_string(Line) + "\n\r\n\r" + text;
	}

};

// ------------------------------------------------------------------
class TException2
{
public:
	std::string File;
	int Line;
	std::string Caption;
	std::string Text;

	TException2(const std::string& file, int line,
		const std::string& text, const std::string& caption)
		: Line(line), Caption(caption)
	{
		size_t pos = file.find_last_of('\\', file.length());
		// Проверку pos == max size_t
		if (pos > 100000)
		{
			File = file; // std::move
		}
		else
		{
			size_t n = file.length() - pos;
			File = file.substr(pos + 1, n - 1);
		}

		Text = "In \"" + File + "\" at line " + std::to_string(Line) + "\n\r\n\r" + text;
	}

};


// ------------------------------------------------------------------
#define MY_ASSERT(condition, text, caption)	\
if (!(condition)) throw TException(__FILE__, __LINE__, text, caption);



// ----------------------------------------------------------------------------
#endif // _MY_OPENGLAPP_1_EXCEPTIONS_HPP_
